import { IPartTimeEmployee } from '../../interfaces/IPartTimeEmployee.js';
import { Employee } from './Employee.js';

export class PartTimeEmployee extends Employee implements IPartTimeEmployee {
  constructor(
    protected employee_id: number,
    protected name: string,
    protected hourlyRate: number,
    protected hoursWorked: number
  ) {
    super(employee_id, name);
    this.hourlyRate = hourlyRate;
    this.hoursWorked = hoursWorked;
  }

  calculateSalary(): number {
    return this.hourlyRate * this.hoursWorked;
  }

  displayDetails(): void {
    console.log('Part Time Employee Details');
    super.displayDetails();
  }

  getHourlyRate(): number {
    return this.hourlyRate;
  }

  getHoursWorked(): number {
    return this.hoursWorked;
  }

  setHourlyRate(rate: number): void {
    this.hourlyRate = rate;
  }

  setHoursWorked(hours: number): void {
    this.hoursWorked = hours;
  }
}
