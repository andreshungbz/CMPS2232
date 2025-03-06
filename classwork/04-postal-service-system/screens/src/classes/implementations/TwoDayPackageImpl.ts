import { PackageImpl } from './PackageImpl';

export class TwoDayPackageImpl extends PackageImpl {
  calculateCost(): number {
    return super.calculateCost() + 5; // Example extra fee for two-day delivery
  }

  printLabel(): void {
    console.log(`Two-Day Shipping Label:`);
    super.printLabel();
  }
}
