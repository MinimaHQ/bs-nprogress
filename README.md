# bs-nprogress

BuckleScript bindings to [nprogress](https://github.com/rstacruz/nprogress).

## Installation

```shell
yarn add bs-nprogress nprogress
npm install --save bs-nprogress nprogress
```

## Usage
Pretty much consistent with [original JS API](https://github.com/rstacruz/nprogress#basic-usage).

```reason
// All arguments are optional
NProgress.configure(
  ~minimum=0.2,
  ~template="<div />"
  ~easing="ease",
  ~speed=200,
  ~trickle=true,
  ~trickleSpeed=300,
  ~showSpinner=false,
  ~parent="#container",
  () // NB: Don't forget to apply unit!
);

NProgress.start();

NProgress.complete(); // original: NProgress.done();

NProgress.forceComplete(); // original: NProgress.done(true);

NProgress.isStarted();

NProgress.set(0.2);

NProgress.inc();

NProgress.remove();

NProgress.status;
```
