// Filename: employeeModel.ts

import { query } from '../db/database.js';
import { Employee } from './classes/Employee.js';
import { FullTimeEmployee } from './classes/FullTimeEmployee.js';
import { PartTimeEmployee } from './classes/PartTimeEmployee.js';
import { NewEmployee } from './NewEmployee.js';

export const insertEmployee = async (emp: NewEmployee): Promise<Employee> => {
  try {
    const result = await query(
      'INSERT INTO employee (type, name) VALUES ($1, $2) RETURNING *',
      [emp.type, emp.name]
    );

    if (result.rowCount === 0) throw new Error('Employee not found.');

    const id = result.rows[0].id;

    switch (emp.type) {
      case 'Full-Time':
        await query('UPDATE employee SET annual_salary = $1 WHERE id = $2', [
          emp.annualSalary,
          id,
        ]);
        return new FullTimeEmployee(id, emp.name, emp.annualSalary!);
      case 'Part-Time':
        await query(
          'UPDATE employee SET hourly_rate = $1, hours_worked = $2 WHERE id = $3',
          [emp.hourlyRate, emp.hoursWorked, id]
        );
        return new PartTimeEmployee(
          id,
          emp.name,
          emp.hourlyRate!,
          emp.hoursWorked!
        );
      default:
        throw new Error('Error in insertEmployee');
    }
  } catch (error) {
    console.error(error);
    throw error;
  }
};

export const readAllEmployees = async (): Promise<Employee[]> => {
  try {
    const employees: Employee[] = [];
    const result = await query('SELECT * FROM employee');

    if (result.rowCount === 0) throw new Error('Employee not found.');

    for (const record of result.rows) {
      switch (record.type) {
        case 'Full-Time':
          employees.push(
            new FullTimeEmployee(record.id, record.name, record.annual_salary)
          );
          break;
        case 'Part-Time':
          employees.push(
            new PartTimeEmployee(
              record.id,
              record.name,
              record.hourly_rate,
              record.hours_worked
            )
          );
          break;
        default:
          throw new Error('Error in readAllEmployees');
      }
    }

    return employees;
  } catch (error) {
    console.error(error);
    throw error;
  }
};

export const readEmployee = async (id: number): Promise<Employee> => {
  try {
    const result = await query('SELECT * FROM employee WHERE id=$1', [id]);
    if (result.rowCount === 0) throw new Error('Employee not found.');

    const employee = result.rows[0];

    switch (employee.type) {
      case 'Full-Time':
        return new FullTimeEmployee(
          employee.id,
          employee.name,
          employee.annual_salary
        );
      case 'Part-Time':
        return new PartTimeEmployee(
          employee.id,
          employee.name,
          employee.hourly_rate,
          employee.hours_worked
        );
      default:
        throw new Error('Error in readEmployee');
    }
  } catch (error) {
    console.error(error);
    throw error;
  }
};
