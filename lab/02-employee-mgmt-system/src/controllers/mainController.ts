// Filename: mainController.ts

import { Request, Response } from 'express';
import {
  insertEmployee,
  readAllEmployees,
  readEmployee,
} from '../models/employeeModel.js';

export const getIndex = async (_req: Request, res: Response) => {
  try {
    const employees = await readAllEmployees();

    res.render('index', {
      employees,
    });
  } catch (error) {
    console.error(error);
    res.redirect('/');
  }
};

export const addEmployee = async (req: Request, res: Response) => {
  try {
    const { type, name } = req.body;

    switch (type) {
      case 'Full-Time':
        const { annual_salary } = req.body;
        await insertEmployee({ type, name, annualSalary: annual_salary });
        res.redirect('/');
        break;
      case 'Part-Time':
        const { hourly_rate, hours_worked } = req.body;
        await insertEmployee({
          type,
          name,
          hourlyRate: hourly_rate,
          hoursWorked: hours_worked,
        });
        res.redirect('/');
        break;
      default:
        throw new Error('Error in addEmployee');
    }
  } catch (error) {
    console.error(error);
    res.redirect('/');
  }
};

export const getEmployee = async (req: Request, res: Response) => {
  try {
    const id = Number(req.params.id);
    if (isNaN(id) || id < 1) throw new Error('Bad ID');

    const employee = await readEmployee(id);

    res.render('employee', {
      type: employee.constructor.name,
      employee,
    });
  } catch (error) {
    console.error(error);
    res.redirect('/');
  }
};
