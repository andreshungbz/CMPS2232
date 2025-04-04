export interface IEmployee {
  calculateSalary(): number;
  displayDetails(): void;

  // getters

  getEmployeeID(): number;
  getName(): string;

  // setters

  setEmployeeID(id: number): void;
  setName(name: string): void;
}
