import { IEmployee } from '../interfaces/IEmployee.js';

export abstract class Employee implements IEmployee {
  constructor(public employee_id: number, public name: string) {
    this.employee_id = employee_id;
    this.name = name;
  }

  calculateSalary(): number {
    return 0;
  }

  displayDetails(): void {
    console.log(`Employee ID: ${this.employee_id}`);
    console.log(`Name: ${this.name}`);
    console.log(`Salary: $${this.calculateSalary()}`);
  }
}
