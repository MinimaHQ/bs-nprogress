[@bs.module "nprogress"] external start : unit => unit = "";

[@bs.module "nprogress"] external complete : unit => unit = "done";

[@bs.module "nprogress"] external forceComplete : Js.boolean => unit = "done";

[@bs.module "nprogress"] external isStarted : unit => bool = "";

[@bs.module "nprogress"] external set : float => unit = "";

[@bs.module "nprogress"] external inc : unit => unit = "";

[@bs.module "nprogress"] external remove : unit => unit = "";

[@bs.module "nprogress"] external status : float = "";

let forceComplete = () => forceComplete(Js.true_);

type jsConfig = {
  .
  "minimum": Js.nullable(float),
  "template": Js.nullable(string),
  "easing": Js.nullable(string),
  "speed": Js.nullable(int),
  "trickle": Js.nullable(Js.boolean),
  "trickleSpeed": Js.nullable(int),
  "showSpinner": Js.nullable(Js.boolean),
  "parent": Js.nullable(string),
};

[@bs.module "nprogress"] external configure : jsConfig => unit = "";

let toNullableJsBoolean = maybeBool =>
  switch (maybeBool) {
  | Some(boolean) => Some(boolean |> Js.Boolean.to_js_boolean)
  | None => None
  };

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
      _,
    ) =>
  configure({
    "minimum": minimum |> Js.Nullable.fromOption,
    "template": template |> Js.Nullable.fromOption,
    "easing": easing |> Js.Nullable.fromOption,
    "speed": speed |> Js.Nullable.fromOption,
    "trickle": trickle |> toNullableJsBoolean |> Js.Nullable.fromOption,
    "trickleSpeed": trickleSpeed |> Js.Nullable.fromOption,
    "showSpinner":
      showSpinner |> toNullableJsBoolean |> Js.Nullable.fromOption,
    "parent": parent |> Js.Nullable.fromOption,
  });
