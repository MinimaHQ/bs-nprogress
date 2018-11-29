[@bs.module "nprogress"] external start: unit => unit = "";
[@bs.module "nprogress"] external complete: unit => unit = "done";
[@bs.module "nprogress"] external forceComplete: bool => unit = "done";
[@bs.module "nprogress"] external isStarted: unit => bool = "";
[@bs.module "nprogress"] external set: float => unit = "";
[@bs.module "nprogress"] external inc: unit => unit = "";
[@bs.module "nprogress"] external incBy: float => unit = "inc";
[@bs.module "nprogress"] external remove: unit => unit = "";
[@bs.module "nprogress"] external status: float = "";

let forceComplete = () => true->forceComplete;

type jsConfig = {
  .
  "minimum": Js.nullable(float),
  "template": Js.nullable(string),
  "easing": Js.nullable(string),
  "speed": Js.nullable(int),
  "trickle": Js.nullable(bool),
  "trickleSpeed": Js.nullable(int),
  "showSpinner": Js.nullable(bool),
  "parent": Js.nullable(string),
};

[@bs.module "nprogress"] external configure: jsConfig => unit = "";

let configure =
    (
      ~minimum: option(float)=?,
      ~template: option(string)=?,
      ~easing: option(string)=?,
      ~speed: option(int)=?,
      ~trickle: option(bool)=?,
      ~trickleSpeed: option(int)=?,
      ~showSpinner: option(bool)=?,
      ~parent: option(string)=?,
      (),
    ) =>
  configure({
    "minimum": minimum->Js.Nullable.fromOption,
    "template": template->Js.Nullable.fromOption,
    "easing": easing->Js.Nullable.fromOption,
    "speed": speed->Js.Nullable.fromOption,
    "trickle": trickle->Js.Nullable.fromOption,
    "trickleSpeed": trickleSpeed->Js.Nullable.fromOption,
    "showSpinner": showSpinner->Js.Nullable.fromOption,
    "parent": parent->Js.Nullable.fromOption,
  });
