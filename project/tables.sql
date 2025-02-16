/* RESET TABLES */

DROP TABLE IF EXISTS employee_type CASCADE;
DROP TABLE IF EXISTS employee CASCADE;

DROP TABLE IF EXISTS visa_type CASCADE;
DROP TABLE IF EXISTS visa_application CASCADE;

DROP TABLE IF EXISTS personal_section CASCADE;
DROP TABLE IF EXISTS travel_section CASCADE;
DROP TABLE IF EXISTS work_section CASCADE;
DROP TABLE IF EXISTS security_section CASCADE;
DROP TABLE IF EXISTS business_section CASCADE;
DROP TABLE IF EXISTS tourist_section CASCADE;
DROP TABLE IF EXISTS student_section CASCADE;

/* EMPLOYEE */

CREATE TABLE employee_type (
	type_id SERIAL PRIMARY KEY,
	type_name VARCHAR(20),
	type_description TEXT
);

CREATE TABLE employee (
	employee_number SERIAL PRIMARY KEY,
	employee_type INT REFERENCES employee_type(type_id),
	first_name VARCHAR(100) NOT NULL,
    last_name VARCHAR(100) NOT NULL,
	social_security_number VARCHAR(50) UNIQUE,
	hashed_password TEXT,
	salary INT
);

/* VISA */

CREATE TABLE visa_type (
	type_id SERIAL PRIMARY KEY,
	type_name VARCHAR(10)
);

CREATE TABLE visa_application (
    application_number SERIAL PRIMARY KEY,
    visa_type INT REFERENCES visa_type(type_id),
    state VARCHAR(50),
    s1_reviewer VARCHAR(100),
    s1_notes TEXT,
    s2_reviewer VARCHAR(100),
    s2_notes TEXT,
    s3_reviewer VARCHAR(100),
    s3_notes TEXT,
	last_updated TIMESTAMP
);

/* FORM SECTIONS */

CREATE TABLE personal_section (
    number INT PRIMARY KEY REFERENCES visa_application(application_number),
    first_name VARCHAR(100) NOT NULL,
    last_name VARCHAR(100) NOT NULL,
    gender VARCHAR(50),
    dob DATE,
    country VARCHAR(50),
    passport_number VARCHAR(50) UNIQUE,
    address TEXT,
    city VARCHAR(50),
    phone VARCHAR(20),
    email VARCHAR(100) UNIQUE
);

CREATE TABLE travel_section (
    number INT PRIMARY KEY REFERENCES visa_application(application_number),
    intended_length_of_stay INT,
    intended_date_of_arrival DATE,
    stay_address TEXT,
    stay_city VARCHAR(50)
);

CREATE TABLE work_section (
    number INT PRIMARY KEY REFERENCES visa_application(application_number),
    occupation VARCHAR(100),
    employer_name VARCHAR(100),
    employer_address TEXT,
    employer_city VARCHAR(50)
);

CREATE TABLE security_section (
    number INT PRIMARY KEY REFERENCES visa_application(application_number),
    communicable_disease BOOL,
    mental_physical_disorder BOOL,
    arrested_convicted BOOL,
    drug_conspiracy BOOL,
	money_laundering BOOL
);

CREATE TABLE business_section (
    number INT PRIMARY KEY REFERENCES visa_application(application_number),
    business_purpose TEXT,
    business_address TEXT,
    business_city VARCHAR(50),
    business_phone VARCHAR(20)
);

CREATE TABLE tourist_section (
    number INT PRIMARY KEY REFERENCES visa_application(application_number),
    purpose TEXT
);

CREATE TABLE student_section (
    number INT PRIMARY KEY REFERENCES visa_application(application_number),
    enrolled_school VARCHAR(200),
    enrolled_school_address TEXT,
    enrollment_year INT,
    enrollment_month INT
);