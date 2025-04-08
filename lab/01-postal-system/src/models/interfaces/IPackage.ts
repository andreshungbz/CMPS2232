// Package Interface (Header)

import { ShippingMethod } from '../../lib/enums/ShippingMethod.js';
import { PackageStatus } from '../../lib/enums/PackageStatus.js';

export interface IPackage {
  // data members (needs to be commented so implementation can apply protected access specifier)

  // trackingNumber: number;
  // senderName: string;
  // senderAddress: string;
  // receiverName: string;
  // receiverAddress: string;
  // weight: number;
  // costPerUnitWeight: number;
  // shippingMethod: ShippingMethod;
  // status: PackageStatus;

  // methods (member functions)
  calculateCost(): number;
  printLabel(): void;
  updateStatus(): boolean;

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
