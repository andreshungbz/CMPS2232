// One Day Package Class Implementation

import { Package } from './Package.js';
import { IOneDayPackage } from '../interfaces/IOneDayPackage.js';

import { ShippingMethod } from '../../lib/enums/ShippingMethod.js';
import { PackageStatus } from '../../lib/enums/PackageStatus.js';

import { query } from '../../db/database.js';

export class OneDayPackage extends Package implements IOneDayPackage {
  // constructor

  constructor(
    protected trackingNumber: number,
    protected senderName: string,
    protected senderAddress: string,
    protected receiverName: string,
    protected receiverAddress: string,
    protected weight: number,
    protected costPerUnitWeight: number,
    protected flatFee: number, // extra flat fee data member
    protected shippingMethod: ShippingMethod = ShippingMethod.OneDay,
    protected status: PackageStatus = PackageStatus.Created
  ) {
    super(
      trackingNumber,
      senderName,
      senderAddress,
      receiverName,
      receiverAddress,
      weight,
      costPerUnitWeight,
      shippingMethod,
      status
    );
  }

  // overridden methods

  calculateCost(): number {
    // add flat fee and 20%
    return (super.calculateCost() + this.getFlatFee()) * 1.2;
  }

  printLabel(): void {
    console.log(`[One Day Package Details]`);
    super.printLabel();
    console.log(`Flat Fee: $${this.getFlatFee()}`);
    console.log(`One Day Package Extra % Fee: 20%`);
    console.log(`Total Cost: $${this.calculateCost()}`);
  }

  // extra methods

  getFlatFee(): number {
    return this.flatFee;
  }

  setFlatFee(flatFee: number): void {
    this.flatFee = flatFee;
  }

  // database methods

  async createRecord(): Promise<void> {
    try {
      await query(
        'INSERT INTO package VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10)',
        [
          this.getTrackingNumber(),
          this.getShippingMethod(),
          this.getStatus(),
          this.getSenderName(),
          this.getSenderAddress(),
          this.getReceiverName(),
          this.getReceiverAddress(),
          this.getWeight(),
          this.getCostPerUnitWeight(),
          this.getFlatFee(),
        ]
      );
    } catch (error) {
      console.error(error);
      throw error;
    }
  }
}
