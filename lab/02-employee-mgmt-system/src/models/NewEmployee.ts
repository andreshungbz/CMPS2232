// Filename: NewEmployee.ts

export interface NewEmployee {
  type: string;
  name: string;
  annualSalary?: number;
  hourlyRate?: number;
  hoursWorked?: number;
}
