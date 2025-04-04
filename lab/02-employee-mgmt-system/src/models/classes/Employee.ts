import { IEmployee } from '../../interfaces/IEmployee.js';

export abstract class Employee implements IEmployee {
  constructor(protected employee_id: number, protected name: string) {
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

  // getters

  getEmployeeID(): number {
    return this.employee_id;
  }

  getName(): string {
    return this.name;
  }

  // setters

  setEmployeeID(id: number): void {
    this.employee_id = id;
  }

  setName(name: string): void {
    this.name = name;
  }
}
