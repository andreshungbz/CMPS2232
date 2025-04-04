/* Filename: tables.sql */

-- script that creates the necessary database table(s)
-- meant to be run after setup.sql and assumes the database and user exists

\echo '\n\033[1;31m[PSQL] Dropping TABLEs\033[0m'

DROP TABLE IF EXISTS employee;
DROP TABLE IF EXISTS employee_type;

\echo '\033[1;34m[PSQL] Creating TABLEs\033[0m'

CREATE TABLE employee_type (
    type VARCHAR(100) PRIMARY KEY,
    description VARCHAR(100) NOT NULL
);

CREATE TABLE employee (
    id SERIAL PRIMARY KEY,
    type VARCHAR(100) REFERENCES employee_type(type),
    name VARCHAR(100) NOT NULL,
    annual_salary NUMERIC(10,2),
    hourly_rate NUMERIC(10,2),
    hours_worked INT
);

INSERT INTO employee_type VALUES
    ('Part-Time', 'An employee who only works part-time.'),
    ('Full-Time', 'An employee who works full-time.');

INSERT INTO employee (type, name, annual_salary, hourly_rate, hours_worked) VALUES
    ('Part-Time', 'Saul Goodman', null, 500, 50),
    ('Full-Time', 'George Kalos', 10000, null, null),
    ('Full-Time', 'Sammy Cool', 20000, null, null);