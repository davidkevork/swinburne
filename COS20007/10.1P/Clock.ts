import Counter from './Counter';

export default class Clock {
  private _hour: Counter;
  private _minute: Counter;
  private _second: Counter;

  public constructor() {
    this._hour = new Counter('Hour');
    this._minute = new Counter('Minute');
    this._second = new Counter('Second');
  }

  public Tick(): void {
    if (this._second.Value < 60) {
      this._second.Increment();
    } else {
      this._second.Reset();
      if (this._minute.Value < 60) {
        this._minute.Increment();
      } else {
        this._minute.Reset();
        if (this._hour.Value < 24) {
          this._hour.Increment();
        } else {
          this._hour.Reset();
        }
      }
    }
  }

  public get Time(): string {
    const pad = (num: number) => {
      let value = num.toString();
      return value.length == 1 ? `0${value}` : value;
    }
    return `${pad(this._hour.Value)}:${pad(this._minute.Value)}:${pad(this._second.Value)}`;
  }

  public Reset(): void {
    this._hour.Reset();
    this._minute.Reset();
    this._second.Reset();
  }
}