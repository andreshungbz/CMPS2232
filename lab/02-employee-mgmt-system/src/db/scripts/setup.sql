/* Filename: setup.sql */

-- script that creates a PostgreSQL database and user for the project
-- this script is meant to be run with the psql PostgreSQL client
-- the user running the script must have the CREATEROLE and CREATEDB attributes
-- (https://www.postgresql.org/docs/17/sql-createrole.html)

\echo '\n\033[1;31m[PSQL] Dropping Database cmps2232_emp_mgmt_sys\033[0m'
DROP DATABASE IF EXISTS cmps2232_emp_mgmt_sys;
DROP USER IF EXISTS emp_user;

\echo '\033[1;34m[PSQL] Creating Database cmps2232_emp_mgmt_sys\033[0m'
CREATE USER emp_user WITH CREATEDB PASSWORD 'swordfish';
GRANT emp_user TO CURRENT_USER;
CREATE DATABASE cmps2232_emp_mgmt_sys OWNER emp_user;
