// Package Class Implementation

import { IPackage } from '../interfaces/IPackage.js';

import { ShippingMethod } from '../../lib/enums/ShippingMethod.js';
import { PackageStatus } from '../../lib/enums/PackageStatus.js';

import { query } from '../../db/database.js';

export abstract class Package implements IPackage {
  // constructor
  // this shorthand automatically declares the data members

  constructor(
    protected trackingNumber: number,
    protected senderName: string,
    protected senderAddress: string,
    protected receiverName: string,
    protected receiverAddress: string,
    protected weight: number,
    protected costPerUnitWeight: number,
    protected shippingMethod: ShippingMethod,
    protected status: PackageStatus = PackageStatus.Created
  ) {}

  // methods (member functions)

  calculateCost(): number {
    return this.getWeight() * this.getCostPerUnitWeight();
  }

  printLabel(): void {
    console.log(`Shipping Method: ${this.getShippingMethod()}`);
    console.log(`Status: ${this.getStatus()}`);
    console.log(
      `From ${this.getSenderName()} (${this.getSenderAddress()}) to ${this.getReceiverName()} (${this.getReceiverAddress()})`
    );
    console.log(`Weight (lbs): ${this.getWeight()}`);
    console.log(`Cost Per Unit Weight: $${this.getCostPerUnitWeight()}`);
  }

  async updateStatus() {
    try {
      switch (this.status) {
        case PackageStatus.Created:
          this.setStatus(PackageStatus.Shipped);
          break;
        case PackageStatus.Shipped:
          this.setStatus(PackageStatus.InTransit);
          break;
        case PackageStatus.InTransit:
          this.setStatus(PackageStatus.Delivered);
          break;
        default:
          throw new Error('Invalid Package Status');
      }

      await query('UPDATE package SET status = $1 WHERE tracking_number = $2', [
        this.getStatus(),
        this.getTrackingNumber(),
      ]);
    } catch (error) {
      console.error(error);
      throw error;
    }
  }

  // getters

  getTrackingNumber(): number {
    return this.trackingNumber;
  }
  getShippingMethod(): ShippingMethod {
    return this.shippingMethod;
  }
  getStatus(): PackageStatus {
    return this.status;
  }
  getSenderName(): string {
    return this.senderName;
  }
  getSenderAddress(): string {
    return this.senderAddress;
  }
  getReceiverName(): string {
    return this.receiverName;
  }
  getReceiverAddress(): string {
    return this.receiverAddress;
  }
  getWeight(): number {
    return this.weight;
  }
  getCostPerUnitWeight(): number {
    return this.costPerUnitWeight;
  }

  // setters

  setTrackingNumber(trackingNumber: number): void {
    this.trackingNumber = trackingNumber;
  }
  setShippingMethod(shippingMethod: ShippingMethod): void {
    this.shippingMethod = shippingMethod;
  }
  setStatus(status: PackageStatus): void {
    this.status = status;
  }
  setSenderName(senderName: string): void {
    this.senderName = senderName;
  }
  setSenderAddress(senderAddress: string): void {
    this.senderAddress = senderAddress;
  }
  setReceiverName(receiverName: string): void {
    this.receiverName = receiverName;
  }
  setReceiverAddress(receiverAddress: string): void {
    this.receiverAddress = receiverAddress;
  }
  setWeight(weight: number): void {
    this.weight = weight;
  }
  setCostPerUnitWeight(costPerUnitWeight: number): void {
    this.costPerUnitWeight = costPerUnitWeight;
  }
}
