
Parse.Cloud.define("orderToiletPaper", function(request, response) {

  var shopifyAppId = 'your-shopify-app-id';
  var shopifyAppPassword = 'your-shopify-app-password';
  var shopifyStoreName = 'your-shopify-store-name';
  var shopifyURL = 'https://' + shopifyAppId + ':' + shopifyAppPassword + '@' + shopifyStoreName + '.myshopify.com/admin/orders.json';

  Parse.Cloud.httpRequest({
    url: shopifyURL,
    method: 'POST',
    headers: { 'Content-Type' : 'application/json' },
    body: {
      order: {
        email: 'fjm@fb.com',
        fulfillment_status: 'fulfilled',
        send_receipt: true,
        line_items: [
          { title: 'Parse Toilet Paper', id: 443357149, quantity: 1, price: 0.00 }
        ]
      }
    }
  }).then(function(data) {
    response.success('Ordered some TP.');
  }, function(error) {
    response.error(error);
  });

});
