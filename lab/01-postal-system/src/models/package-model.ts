// Filename: package-model.ts
// various functions that interact with the database

import { query } from '../db/database.js';
import { ShippingMethod } from '../lib/enums/ShippingMethod.js';
import { OneDayPackage } from './classes/OneDayPackage.js';
import { Package } from './classes/Package.js';
import { TwoDayPackage } from './classes/TwoDayPackage.js';

// READ

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
            pkg.weight,
            pkg.cost_per_unit_weight,
            pkg.flat_fee,
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
            pkg.weight,
            pkg.cost_per_unit_weight,
            pkg.flat_fee,
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
          pkg.weight,
          pkg.cost_per_unit_weight,
          pkg.flat_fee,
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
          pkg.weight,
          pkg.cost_per_unit_weight,
          pkg.flat_fee,
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
