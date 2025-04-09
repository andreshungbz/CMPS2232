// Package Interface (Header)

import { ShippingMethod } from '../../lib/enums/ShippingMethod.js';
import { PackageStatus } from '../../lib/enums/PackageStatus.js';

export interface IPackage {
  // methods (member functions)
  calculateCost(): number;
  printLabel(): void;
  updateStatus(): void;

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
}
