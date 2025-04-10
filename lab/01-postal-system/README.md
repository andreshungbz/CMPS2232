# Lab 1 - Postal System

The Postal System web application is a demonstration of using object-oriented programming principles. It combines the use of classes, a simple frontend, and a PostgreSQL database for data persistence. It allows viewing a list of two types of packages, adding packages, deleting packages, and updating their statuses.

This project was done by Andres Hung for CMPS2232 Object Oriented Programming course in the 2024-2 semester.

## Noteable Files/Directories

### `/src/models/classes` & `/src/models/interfaces` (Classes)

The TypeScript interfaces in `/src/models/interfaces` are analogous to C++ header files and ensures the classes adhere to the defined structure through the `implements` keyword. Data members are not declared here, but in the class definitions in order to enforce access specifiers. If they were declared here, they must be public. Class method implementations are located in the exported class files in `/src/models/classes`.

### MVC Architecture

This project follows a simple MVC architecture. EJS HTML templates are located in `/views`, controllers are in `/src/controllers/main-controller.ts`, and the models are in `/src/models/package-model.ts`. Bringing everything together is the `/src/main.ts` file which creates a basic Express server and the `/src/db/database.ts` file which handles the connection to the PostgreSQL database.

## Running the Project

> [!NOTE]  
> Ensure you have Node.js installed and a PostgreSQL server running on your machine with at `postgres` superuser.

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

4. Setup the database and example data.

> [!NOTE]  
> You may be prompted for a password during this process. The default password for `postal_user` is `swordfish`. The commands executed are located in the `package.json` file and the database scripts under `/src/db/scripts`.

```
npm run initiatedb
```

5. Run the server.

```
npm run dev
```

6. Navigate to the address printed in the console or `http://localhost:3000` in your web browser.

## Assumptions

- Package is an abstract class and cannot be instantiated.
- One-Day Packages and Two-Day Packages calculate their cost differently but have the same extra data members.
