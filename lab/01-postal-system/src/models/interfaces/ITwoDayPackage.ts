// Two Day Package Interface (Header)

import { IPackage } from './IPackage.js';

export interface ITwoDayPackage extends IPackage {
  // getters
  getFlatFee(): number;

  // setters
  setFlatFee(flateFee: number): void;

  // database
  createRecord(): Promise<void>;
}
