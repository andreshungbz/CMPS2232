// Filename: missingRoute.ts
// middleware to handle any non-existing routes; returns a 404 message

import { Request, Response } from 'express';

const missingRoute = (_req: Request, res: Response) => {
  res.status(404);
  res.render('error', { error: new Error('404 Page Not Found') });
};

export default missingRoute;
