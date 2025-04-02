import { IFullTimeEmployee } from '../interfaces/IFullTimeEmployee.js';
import { Employee } from './Employee.js';

export class FullTimeEmployee extends Employee implements IFullTimeEmployee {
  constructor(
    public employee_id: number,
    public name: string,
    public annualSalary: number
  ) {
    super(employee_id, name);
    this.annualSalary = annualSalary;
  }

  calculateSalary(): number {
    return this.annualSalary;
  }
}
