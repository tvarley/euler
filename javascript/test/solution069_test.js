var assert = require('assert');
var solution069 = require('../src/euler/solution069');

describe('Solution069', function() {
  describe('answer', function() {
    it('will answer problem 069', function() {
      assert.equal(solution069.answer(), 510510);
    });
  });
});