export default class Counter {
  private _count: number;
  private _name: string;
  
  public constructor(name: string) {
    this._name = name;
    this._count = 0;
  }

  public Increment(): void {
    this._count++;
  }

  public Reset(): void {
    this._count = 0;
  }

  public get Name(): string {
    return this._name;
  }
  public set Name(name: string) {
    this._name = name;
  }

  public get Value(): number {
    return this._count;
  }
}