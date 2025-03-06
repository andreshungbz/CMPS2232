import { PackageImpl } from './PackageImpl';

export class OneDayPackageImpl extends PackageImpl {
  calculateCost(): number {
    return super.calculateCost() + 10; // Example extra fee for one-day delivery
  }

  printLabel(): void {
    console.log(`One-Day Shipping Label:`);
    super.printLabel();
  }
}
