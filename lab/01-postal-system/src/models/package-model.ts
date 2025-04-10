// Filename: package-model.ts
// various functions that interact with the database

import { query } from '../db/database.js';

import { ShippingMethod } from '../lib/enums/ShippingMethod.js';
import { Package } from './classes/Package.js';
import { OneDayPackage } from './classes/OneDayPackage.js';
import { TwoDayPackage } from './classes/TwoDayPackage.js';

// READ

// retrieves all packages and creates the appropriate derived class objects
export const readPackages = async (): Promise<Package[]> => {
  try {
    const result = await query(
      'SELECT * FROM package ORDER BY tracking_number ASC'
    );

    return result.rows.map((pkg) => {
      switch (pkg.shipping_method) {
        case ShippingMethod.OneDay:
          return new OneDayPackage(
            pkg.tracking_number,
            pkg.sender_name,
            pkg.sender_address,
            pkg.receiver_name,
            pkg.receiver_address,
            Number(pkg.weight),
            Number(pkg.cost_per_unit_weight),
            Number(pkg.flat_fee),
            ShippingMethod.OneDay,
            pkg.status
          );
        case ShippingMethod.TwoDay:
          return new TwoDayPackage(
            pkg.tracking_number,
            pkg.sender_name,
            pkg.sender_address,
            pkg.receiver_name,
            pkg.receiver_address,
            Number(pkg.weight),
            Number(pkg.cost_per_unit_weight),
            Number(pkg.flat_fee),
            ShippingMethod.TwoDay,
            pkg.status
          );
        default:
          throw new Error('Invalid Shipping Method');
      }
    });
  } catch (error) {
    console.error(error);
    throw error;
  }
};

// retrieves a single package from the databsae and creates the appropriate derived class object
export const readPackage = async (trackingNumber: number): Promise<Package> => {
  try {
    const result = await query(
      'SELECT * FROM package WHERE tracking_number = $1',
      [trackingNumber]
    );

    if (result.rowCount === 0) throw new Error('Package Not Found');

    const pkg = result.rows[0];
    switch (pkg.shipping_method) {
      case ShippingMethod.OneDay:
        return new OneDayPackage(
          pkg.tracking_number,
          pkg.sender_name,
          pkg.sender_address,
          pkg.receiver_name,
          pkg.receiver_address,
          Number(pkg.weight),
          Number(pkg.cost_per_unit_weight),
          Number(pkg.flat_fee),
          ShippingMethod.OneDay,
          pkg.status
        );
      case ShippingMethod.TwoDay:
        return new TwoDayPackage(
          pkg.tracking_number,
          pkg.sender_name,
          pkg.sender_address,
          pkg.receiver_name,
          pkg.receiver_address,
          Number(pkg.weight),
          Number(pkg.cost_per_unit_weight),
          Number(pkg.flat_fee),
          ShippingMethod.TwoDay,
          pkg.status
        );
      default:
        throw new Error('Invalid Shipping Method');
    }
  } catch (error) {
    console.error(error);
    throw error;
  }
};

// used to determine the next tracking number to use when adding a new package
export const readNextTrackingNumber = async (): Promise<number> => {
  try {
    const result = await query(
      'SELECT MAX(tracking_number) AS max_tracking_number FROM package',
      []
    );

    return (result.rowCount ?? 0) > 0
      ? result.rows[0].max_tracking_number + 1
      : 1;
  } catch (error) {
    console.error(error);
    throw error;
  }
};

// DELETE

// deletes a package by its tracking number
export const deletePackage = async (trackingNumber: number) => {
  try {
    await query('DELETE FROM package WHERE tracking_number = $1', [
      trackingNumber,
    ]);
  } catch (error) {
    console.error(error);
    throw error;
  }
};
