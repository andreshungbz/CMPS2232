import { IEmployee } from './IEmployee.js';

export interface IPartTimeEmployee extends IEmployee {
  calculateSalary(): number;
  displayDetails(): void;

  getHourlyRate(): number;
  getHoursWorked(): number;

  setHourlyRate(rate: number): void;
  setHoursWorked(hours: number): void;
}
