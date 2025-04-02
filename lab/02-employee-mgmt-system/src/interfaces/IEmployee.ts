export interface IEmployee {
  employee_id: number;
  name: string;

  calculateSalary(): number;
  displayDetails(): void;
}
