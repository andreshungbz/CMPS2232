DROP TABLE IF EXISTS package_type CASCADE;
DROP TABLE IF EXISTS package CASCADE;
DROP TABLE IF EXISTS employee CASCADE;

CREATE TABLE package_type (
id SERIAL PRIMARY KEY,
name TEXT
);

CREATE TABLE package (
tracking_number SERIAL PRIMARY KEY,
package_type INT REFERENCES package_type(id),
shipping_method TEXT NOT NULL,
status TEXT NOT NULL CHECK (status IN ('Created', 'Shipped', 'In Transit', 'Delivered')),
sender_name TEXT,
sender_address TEXT,
receiver_name TEXT NOT NULL,
receiver_address TEXT NOT NULL,
weight NUMERIC(10,2) NOT NULL,
cost_per_unit_weight NUMERIC(10,2) NOT NULL,
flat_fee NUMERIC(10,2)
);

CREATE TABLE employee (
employee_id SERIAL PRIMARY KEY,
name TEXT NOT NULL,
hashed_password TEXT NOT NULL
);