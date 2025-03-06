export interface IPackage {
  getTrackingNumber(): number;
  getShippingMethod(): string;
  getStatus(): string;
  getSenderName(): string;
  getSenderAddress(): string;
  getReceiverName(): string;
  getReceiverAddress(): string;
  getWeight(): number;
  getCostPerUnitWeight(): number;
  getFlatFee(): number;

  setTrackingNumber(trackingNumber: number): void;
  setShippingMethod(shippingMethod: string): void;
  setStatus(status: string): void;
  setSenderName(senderName: string): void;
  setSenderAddress(senderAddress: string): void;
  setReceiverName(receiverName: string): void;
  setReceiverAddress(receiverAddress: string): void;
  setWeight(weight: number): void;
  setCostPerUnitWeight(costPerUnitWeight: number): void;
  setFlatFee(flatFee: number): void;

  calculateCost(): number;
  printLabel(): void;
  updateStatus(status: string): boolean;
}
