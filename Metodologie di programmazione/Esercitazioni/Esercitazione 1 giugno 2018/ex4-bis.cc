#include <oci.h> // Oracle interface
#include <libpq/libpq-fs.h> // PostgreSQL interface
// ...

class DBSession {
private:
  typedef /* omissis */ Ora_backend;
  typedef /* omissis */ Pg_backend;
  Ora_backend* ob;
  Pg_backend* pb;
  // ... omissis ...

public:

  void begin() {
    // Do nothing in the Oracle case.
    if (pb) {
      PgStatus status = PQexec(pb, "BEGIN");
      if (status != PGRES_OK) throw Pg_Exception(status);
    }
  }

  void commit() {
    if (ob) {
      OraStatus status = OCITransCommit(ob, OCI_DEFAULT);
      if (status != OCI_SUCCESS) throw Ora_Exception(status);
    } else {
      PgStatus status = PQexec(pb, "COMMIT");
      if (status != PGRES_OK) throw Pg_Exception(status);
    }
  }

  void rollback() {
    if (ob) {
      OraStatus status = OCITransRollback(ob, OCI_DEFAULT);
      if (status != OCI_SUCCESS) throw Ora_Exception(status);
    } else {
      PgStatus status = PQexec(pb, "ROLLBACK");
      if (status != PGRES_OK) throw Pg_Exception(status);
    }
  }

  // ... altre funzioni omesse.

};

/////////////////////////////////////////////////////////////7

// "Soluzione"

/******************** FILE DBSession.hh ********************/

class DBSession {
public:
  virtual void begin() = 0;
  virtual void commit() = 0;
  virtual void rollback() = 0;
  // ... altre funzioni omesse.
  virtual ~DBSession() {}
};

/******************** FILE Oracle_Session.hh ********************/

#include "DBSession.hh" // Interfaccia astratta da implementare
#include <oci.h>        // Oracle interface

class Oracle_DBSession : public DBSession {
private:
  typedef /* omissis */ Ora_backend;
  Ora_backend* ob;
  // ... omissis ...

public:
  void begin() override { /* Do nothing. */ }

  void commit() override {
    OraStatus status = OCITransCommit(ob, OCI_DEFAULT);
    if (status != OCI_SUCCESS) throw Ora_Exception(status);
  }

  void rollback() override {
    OraStatus status = OCITransRollback(ob, OCI_DEFAULT);
    if (status != OCI_SUCCESS) throw Ora_Exception(status);
  }

  // ... altre funzioni omesse (compreso il costruttore che
  // inizializza in modo appropriato il puntatore ob).
};

/******************** FILE PostgreSQL_Session.hh ********************/

#include "DBSession.hh" // Interfaccia astratta da implementare
#include <libpq/libpq-fs.h> // PostgreSQL interface

class PostgreSQL_DBSession : public DBSession {
private:
  typedef /* omissis */ Pg_backend;
  Pg_backend* pb;
  // ... omissis ...

public:
  void begin() override {
    PgStatus status = PQexec(pb, "BEGIN");
    if (status != PGRES_OK) throw Pg_Exception(status);
  }

  void commit() override {
    PgStatus status = PQexec(pb, "COMMIT");
    if (status != PGRES_OK) throw Pg_Exception(status);
  }

  void rollback() override {
    PgStatus status = PQexec(pb, "COMMIT");
    if (status != PGRES_OK) throw Pg_Exception(status);
  }

  // ... altre funzioni omesse (compreso il costruttore che
  // inizializza in modo appropriato il puntatore pb).
};
