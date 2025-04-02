/* Filename: tables.sql */

-- script that creates the necessary database table(s)
-- meant to be run after setup.sql and assumes the database and user exists

\echo '\n\033[1;31m[PSQL] Dropping TABLEs\033[0m'

DROP TABLE IF EXISTS employee;
DROP TABLE IF EXISTS employee_type;

\echo '\033[1;34m[PSQL] Creating TABLEs\033[0m'

CREATE TABLE employee_type (
    id SERIAL PRIMARY KEY,
    description VARCHAR(100) NOT NULL
);

CREATE TABLE employee (
    id SERIAL PRIMARY KEY,
    type INT REFERENCES employee_type(id),
    name VARCHAR(100) NOT NULL,
    annual_salary NUMERIC(10,2),
    hourly_rate NUMERIC(10,2),
    hours_worked INT
);