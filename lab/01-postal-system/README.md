# Lab 1 - Postal System

The Postal System web application is a demonstration of using object-oriented programming principles. It combines the use of classes, a simple frontend, and a PostgreSQL database for data persistence. It allows viewing a list of two types of packages, adding packages, deleting packages, and updating their statuses.

This project was done by Andres Hung for CMPS2232 Object Oriented Programming course in the 2024-2 semester.

## Noteable Files/Directories

### `/src/models/classes` & `/src/models/interfaces` (Classes)

The TypeScript interfaces in `/src/models/interfaces` are analogous to C++ header files and ensures the classes adhere to the defined structure through the `implements` keyword. Data members are not declared here, but in the class definitions in order to enforce access specifiers. If they were declared here, they must be public. Class method implementations are located in the exported class files in `/src/models/classes`.

### 'screenshots' (Screenshots)

The screenshots directory contains images of the web application in action. The running application steps should work but everyone's PostgreSQL could be set up differently. If there are any unusual problems let me know.

### MVC Architecture

This project follows a simple MVC architecture. EJS HTML templates are located in `/views`, controllers are in `/src/controllers/main-controller.ts`, and the models are in `/src/models/package-model.ts`. Bringing everything together is the `/src/main.ts` file which creates a basic Express server and the `/src/db/database.ts` file which handles the connection to the PostgreSQL database.

## Running the Project

> [!NOTE]  
> Ensure you have Node.js installed and a PostgreSQL server running on your machine with a `postgres` superuser and the default `postgres` database. Instructions assume a Linux environment.

1. Change directory to the project root.

```
cd 01-postal-system
```

2. Copy sample environment variables to a new file.

```
cp .env.example .env
```

3. Install project dependencies.

```
npm install
```

## Database Steps

1. Login to `psql` as the `postgres` superuser and paste the following in the `psql` prompt:

```
DROP DATABASE IF EXISTS cmps2232_postal_sys;
DROP USER IF EXISTS postal_user;
CREATE USER postal_user WITH CREATEDB PASSWORD 'swordfish';
CREATE DATABASE cmps2232_postal_sys OWNER postal_user;
```

2. Login as `postal_user` in the new database

```
\c cmps2232_postal_sys postal_user
```

3. Create the tables

```
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
```

4. Insert some initial data

```
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
```

## Run the server

```
npm run dev
```

Navigate to the address printed in the console or `http://localhost:3000` in your web browser.

## Assumptions

- Package is an abstract class and cannot be instantiated.
- One-Day Packages and Two-Day Packages calculate their cost differently but have the same extra data members.
