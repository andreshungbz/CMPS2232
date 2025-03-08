// Package Interface

import { ShippingMethod } from '../enums/shippingMethod';
import { PackageStatus } from '../enums/packageStatus';

export interface IPackage {
  // methods (member functions)

  // getters
  getTrackingNumber(): number;
  getShippingMethod(): ShippingMethod;
  getStatus(): PackageStatus;
  getSenderName(): string;
  getSenderAddress(): string;
  getReceiverName(): string;
  getReceiverAddress(): string;
  getWeight(): number;
  getCostPerUnitWeight(): number;

  // setters
  setTrackingNumber(trackingNumber: number): void;
  setShippingMethod(shippingMethod: ShippingMethod): void;
  setStatus(status: PackageStatus): void;
  setSenderName(senderName: string): void;
  setSenderAddress(senderAddress: string): void;
  setReceiverName(receiverName: string): void;
  setReceiverAddress(receiverAddress: string): void;
  setWeight(weight: number): void;
  setCostPerUnitWeight(costPerUnitWeight: number): void;

  calculateCost(): number;
  printLabel(): void;
  updateStatus(): boolean;
}
