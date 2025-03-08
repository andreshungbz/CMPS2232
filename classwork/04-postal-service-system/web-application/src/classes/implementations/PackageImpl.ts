// Package Class Implementation

import { PackageStatus } from '../enums/packageStatus';
import { ShippingMethod } from '../enums/shippingMethod';
import { IPackage } from '../interfaces/IPackage';

export class PackageImpl implements IPackage {
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
    protected status: PackageStatus
  ) {}

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

  calculateCost(): number {
    return this.weight * this.costPerUnitWeight;
  }

  // methods (member functions)

  printLabel(): void {
    console.log(`[Package Details]`);
    console.log(`Shipping Method: ${this.shippingMethod}`);
    console.log(`Status: ${this.status}`);
    console.log(
      `From ${this.senderName} (${this.senderAddress}) to ${this.receiverName} (${this.senderAddress})`
    );
    console.log(`Weight (lbs): ${this.weight}`);
    console.log(`Cost Per Unit Weight: $${this.costPerUnitWeight}`);

    console.log(`Total Cost: $${this.calculateCost()}`);
  }

  updateStatus(): boolean {
    switch (this.status) {
      case PackageStatus.Created:
        this.status = PackageStatus.Shipped;
        return true;
      case PackageStatus.Shipped:
        this.status = PackageStatus.InTransit;
        return true;
      case PackageStatus.InTransit:
        this.status = PackageStatus.Delivered;
        return true;
      case PackageStatus.Delivered:
        return false;
    }
  }
}
