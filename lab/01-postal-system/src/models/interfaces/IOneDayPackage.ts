// One Day Package Interface (Header)

import { IPackage } from './IPackage.js';

export interface IOneDayPackage extends IPackage {
  // getters
  getFlatFee(): number;

  // setters
  setFlatFee(flateFee: number): void;

  // database
  createRecord(): Promise<void>;
}
