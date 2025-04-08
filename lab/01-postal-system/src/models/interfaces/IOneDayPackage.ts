// One Day Package Interface (Header)

import { IPackage } from './IPackage.js';

export interface IOneDayPackage extends IPackage {
  // data members (needs to be commented so implementation can apply protected access specifier)

  // flatFee: number;

  // getters
  getFlatFee(): number;

  // setters
  setFlatFee(flateFee: number): void;
}
