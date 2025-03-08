// One Day Package Interface

import { IPackage } from './IPackage';

export interface IOneDayPackage extends IPackage {
  // getters
  getFlatFee(): number;

  // setters
  setFlatFee(flateFee: number): void;
}
