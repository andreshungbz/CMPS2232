# Postal System Classes & Screens Demo

> [!NOTE]  
> This demo only showcases classes and basic screens without any backend functionality.

Done by Andres Hung for CMPS2232. This project uses Node.js, Express.js, and EJS templating in accordance to what we're doing in CMPS2212 GUI Programming. TypeScript is used for the classes, but also for everything else.

## Relevant Files (No Installation Required)

Since installation expects running in some Unix environment, if you want to examine the relevant files directly instead of doing any installation, they can be examined in the following directories:

### `/src/classes` (Classes)

The closest analogue I could make to C++ header/source files is using TypeScript interfaces and classes. Interfaces acts as the header files because they conveniently show all of the methods to be implemented by the class, although there are some quirks (e.g. can't have private/protected specifiers so they have to go in the class file). The class files act as the implementation files where you can see the properties and methods details. In practice, the class files are imported (as opposed to to including header files in C++).

For example, `/src/classes/package/IPackage.ts` is the "header file" for the Package class, and `/src/classes/package/Package.ts` is the implementation file for the Package class.

### `/src/controllers/main-controller.ts` and `/src/utils/data.ts` (Class Usage)

You can see instances of the classes being instantiated using the constructor here.

### `/screenshots` (Screens)

Screenshots of the EJS views in a running application.

## Running the Project

The main application just has simple navigation to the relevant screens.

To run the application, do the following steps:

1. Have Node LTS version installed.
2. Change directory to the project root.
3. Install the dependencies with the command:

```
npm install
```

4. Run the server with the command:

```
npm run dev
```

5. The console log will show the link with the appropriate port (3000 by default) that can be opened in the browser.

## Assumptions

- Package is NOT an abstract class and represents a regular package with not expedited shipping.
