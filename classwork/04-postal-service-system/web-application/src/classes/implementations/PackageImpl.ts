export class PackageImpl {
  constructor(
    protected trackingNumber: number,
    protected senderName: string,
    protected senderAddress: string,
    protected receiverName: string,
    protected receiverAddress: string,
    protected weight: number,
    protected costPerUnitWeight: number,
    protected flatFee: number,
    protected shippingMethod: string,
    protected status: string
  ) {}

  getTrackingNumber(): number {
    return this.trackingNumber;
  }
  getShippingMethod(): string {
    return this.shippingMethod;
  }
  getStatus(): string {
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
  getFlatFee(): number {
    return this.flatFee;
  }

  setTrackingNumber(trackingNumber: number): void {
    this.trackingNumber = trackingNumber;
  }
  setShippingMethod(shippingMethod: string): void {
    this.shippingMethod = shippingMethod;
  }
  setStatus(status: string): void {
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
  setFlatFee(flatFee: number): void {
    this.flatFee = flatFee;
  }

  calculateCost(): number {
    return this.weight * this.costPerUnitWeight + this.flatFee;
  }

  printLabel(): void {
    console.log(
      `Shipping from ${this.senderName} (${this.senderAddress}) to ${this.receiverName} (${this.receiverAddress})`
    );
  }

  updateStatus(status: string): boolean {
    this.status = status;
    return true;
  }
}
