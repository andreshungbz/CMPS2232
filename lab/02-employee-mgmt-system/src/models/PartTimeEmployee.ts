import { IPartTimeEmployee } from '../interfaces/IPartTimeEmployee.js';
import { Employee } from './Employee.js';

export class PartTimeEmployee extends Employee implements IPartTimeEmployee {
  constructor(
    public employee_id: number,
    public name: string,
    public hourlyRate: number,
    public hoursWorked: number
  ) {
    super(employee_id, name);
    this.hourlyRate = hourlyRate;
    this.hoursWorked = hoursWorked;
  }

  calculateSalary(): number {
    return this.hourlyRate * this.hoursWorked;
  }
}
