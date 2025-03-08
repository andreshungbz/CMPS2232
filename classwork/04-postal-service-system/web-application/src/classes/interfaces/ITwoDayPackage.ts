// Two Day Package Interface

import { IPackage } from './IPackage';

export interface ITwoDayPackage extends IPackage {
  // getters
  getFlatFee(): number;

  // setters
  setFlatFee(flateFee: number): void;
}
