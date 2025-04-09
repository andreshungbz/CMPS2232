/* Filename: tables.sql */

-- script that creates the necessary database table(s)
-- meant to be run after setup.sql and assumes the database and user exists

\echo '\n\033[1;31m[PSQL] Dropping TABLEs\033[0m'

DROP TABLE IF EXISTS employee;
DROP TABLE IF EXISTS employee_type;

\echo '\033[1;34m[PSQL] Creating TABLEs\033[0m'

CREATE TABLE package_status (
    status VARCHAR(100) PRIMARY KEY,
    description VARCHAR(100) NOT NULL
);

CREATE TABLE shipping_method (
    method VARCHAR(100) PRIMARY KEY,
    description VARCHAR(100) NOT NULL
);

CREATE TABLE package (
    tracking_number SERIAL PRIMARY KEY,
    shipping_method VARCHAR(100) NOT NULL REFERENCES shipping_method(method),
    status VARCHAR(100) NOT NULL REFERENCES  package_status(status),
    sender_name TEXT NOT NULL,
    sender_address TEXT NOT NULL,
    receiver_name TEXT NOT NULL,
    receiver_address TEXT NOT NULL,
    weight NUMERIC(10,2) NOT NULL,
    cost_per_unit_weight NUMERIC(10,2) NOT NULL,
    flat_fee NUMERIC(10,2)
);

\echo '\033[1;34m[PSQL] INSERTing Example Data\033[0m'

INSERT INTO package_status VALUES
    ('Created', 'Initial status where a package entry has been created.'),
    ('Shipped', 'When the package has left its initial facility.'),
    ('In-Transit', 'A package that is in another shipping facility other than the first.'),
    ('Delivered', 'A package that has reached its recipient.');

INSERT INTO shipping_method VALUES
    ('One-Day', 'Packages to be delivered in one day.'),
    ('Two-Day', 'Packages to be delivered in two days.');

INSERT INTO package (
    shipping_method, status, sender_name, sender_address, 
    receiver_name, receiver_address, weight, cost_per_unit_weight, flat_fee
) VALUES
    ('One-Day', 'Created', 'Alice Johnson', '123 Elm St, Springfield', 
     'Bob Smith', '456 Oak St, Shelbyville', 2.5, 10.00, 5.00),
    ('Two-Day', 'Shipped', 'Charlie Brown', '789 Pine St, Capital City', 
     'Diana Prince', '101 Maple St, Metropolis', 5.0, 8.00, 3.00),
    ('One-Day', 'In-Transit', 'Eve Adams', '321 Birch St, Gotham', 
     'Frank Castle', '654 Cedar St, Star City', 1.2, 12.00, 4.00);