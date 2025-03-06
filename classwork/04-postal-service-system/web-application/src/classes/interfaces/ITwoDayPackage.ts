import { IPackage } from './IPackage';

export interface ITwoDayPackage extends IPackage {
  calculateCost(): number;
}
