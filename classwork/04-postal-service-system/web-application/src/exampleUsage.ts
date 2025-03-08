import { Package } from './classes/Package';
import { OneDayPackage } from './classes/OneDayPackage';
import { TwoDayPackage } from './classes/TwoDayPackage';

const packageTest = new Package(
  123456,
  'John Doe',
  '123 Main St',
  'Jane Smith',
  '456 Elm St',
  2.5,
  1.0
);

const oneDayPackageTest = new OneDayPackage(
  654321,
  'Alice Johnson',
  '789 Oak St',
  'Bob Brown',
  '101 Pine St',
  2.0,
  4.0,
  2.0
);

const twoDayPackageTest = new TwoDayPackage(
  987654,
  'Charlie Davis',
  '202 Maple St',
  'Dana White',
  '303 Birch St',
  2.0,
  4.0,
  5.0
);

packageTest.printLabel();
console.log();
oneDayPackageTest.printLabel();
console.log();
twoDayPackageTest.printLabel();

twoDayPackageTest.updateStatus();
console.log();
console.log('After calling updateStatus() on TwoDayPackageTest');
console.log();
twoDayPackageTest.printLabel();
