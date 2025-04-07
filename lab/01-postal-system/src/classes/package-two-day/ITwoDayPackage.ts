// Two Day Package Interface (Header)

import { IPackage } from '../package/IPackage';

export interface ITwoDayPackage extends IPackage {
  // data members (needs to be commented so implementation can apply protected access specifier)

  // flatFee: number;

  // getters
  getFlatFee(): number;

  // setters
  setFlatFee(flateFee: number): void;
}
