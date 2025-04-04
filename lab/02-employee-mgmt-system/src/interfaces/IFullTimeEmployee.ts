import { IEmployee } from './IEmployee.js';

export interface IFullTimeEmployee extends IEmployee {
  calculateSalary(): number;
  displayDetails(): void;

  getAnnualSalary(): number;
  setAnnualSalary(annual_salary: number): void;
}
