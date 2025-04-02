import { IEmployee } from './IEmployee.js';

export interface IPartTimeEmployee extends IEmployee {
  hourlyRate: number;
  hoursWorked: number;
}
