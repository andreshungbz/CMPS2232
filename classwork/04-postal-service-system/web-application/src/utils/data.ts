import { Package } from '../classes/Package';
import { OneDayPackage } from '../classes/OneDayPackage';
import { TwoDayPackage } from '../classes/TwoDayPackage';
import { PackageStatus } from '../classes/enums/packageStatus';
import { ShippingMethod } from '../classes/enums/shippingMethod';

export const data = [
  new Package(
    123456,
    'John Doe',
    '123 Main St',
    'Jane Smith',
    '456 Elm St',
    2.5,
    1.0,
    ShippingMethod.Standard,
    PackageStatus.Created
  ),
  new OneDayPackage(
    654321,
    'Alice Johnson',
    '789 Oak St',
    'Bob Brown',
    '101 Pine St',
    2.0,
    4.0,
    2.0,
    ShippingMethod.OneDay,
    PackageStatus.Shipped
  ),
  new TwoDayPackage(
    987654,
    'Charlie Davis',
    '202 Maple St',
    'Dana White',
    '303 Birch St',
    3.0,
    3.0,
    5.0,
    ShippingMethod.TwoDay,
    PackageStatus.InTransit
  ),
];
