import { Package } from './classes/Package';
import { OneDayPackage } from './classes/OneDayPackage';
import { TwoDayPackage } from './classes/TwoDayPackage';

const package1 = new Package(
  123456,
  'John Doe',
  '123 Main St',
  'Jane Smith',
  '456 Elm St',
  2.5,
  1.0,
  5.0
);

const oneDayPackage = new OneDayPackage(
  654321,
  'Alice Johnson',
  '789 Oak St',
  'Bob Brown',
  '101 Pine St',
  3.0,
  1.5,
  10.0
);

const twoDayPackage = new TwoDayPackage(
  987654,
  'Charlie Davis',
  '202 Maple St',
  'Dana White',
  '303 Birch St',
  4.0,
  2.0,
  15.0
);

console.log('Package 1 Cost:', package1.calculateCost());
package1.printLabel();

console.log('One Day Package Cost:', oneDayPackage.calculateCost());
oneDayPackage.printLabel();

console.log('Two Day Package Cost:', twoDayPackage.calculateCost());
twoDayPackage.printLabel();

console.log('hiya');
