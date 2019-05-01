var assert = require('assert');
var solution001 = require('../src/euler/solution001');

describe('Solution001', function() {
  describe('answer', function() {
    it('will answer problem 001', function() {
      assert.equal(solution001.answer(), 233168);
    });
  });
});
