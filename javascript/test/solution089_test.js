var assert = require('assert');
var solution089 = require('../src/euler/solution089');

describe('Solution089', function() {
  describe('answer', function() {
    it('will answer problem 089', function() {
      assert.equal(solution089.answer(), 743);
    });
  });
});