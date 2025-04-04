import { IFullTimeEmployee } from '../../interfaces/IFullTimeEmployee.js';
import { Employee } from './Employee.js';

export class FullTimeEmployee extends Employee implements IFullTimeEmployee {
  constructor(
    protected employee_id: number,
    protected name: string,
    protected annualSalary: number
  ) {
    super(employee_id, name);
    this.annualSalary = annualSalary;
  }

  calculateSalary(): number {
    return this.annualSalary;
  }

  displayDetails(): void {
    console.log('Full Time Employee Details');
    super.displayDetails();
  }

  getAnnualSalary(): number {
    return this.annualSalary;
  }

  setAnnualSalary(annual_salary: number) {
    this.annualSalary = annual_salary;
  }
}
